import copy
import heapq

#Implements Gale-Shapely Algorithm with support for unequal group sizes
#Pre: 
#   prefA: preference list for men as map{ia : list[nB]}
#   prefB: preference list for women as map{ib : list[nA]}
#Post:
#   matches: list of matches as map{iB : iA}
def galeShapely(preferenceA, preferenceB):
    #copy lists so as to not change originals
    prefA = copy.deepcopy(preferenceA)
    prefB = copy.deepcopy(preferenceB)

    #copy prefA into priority queue
    listA = list(prefA.items())
    prefA = heapq.heapify(listA) #turn into heapq 

    #Handles unequal sizes
    if len(preferenceA) != len(prefB): return None

    #initialize structures
    matches = {}
    engagedA = {}
    engagedB = {}

    #while there is an unengaged man who hasn't proposed to every woman
    while len(dict(prefA)) != 0:
        print('men:' + str(dict(prefA)))
        print('women:' + str(prefB))
        print('engagedm:' + str(engagedA))
        print('engagedw:' + str(engagedB))

        #get first unengaged man and his top choice
        pair = prefA.get()
        a = pair[0]
        preflist = pair[1]
        b = preflist.pop(0) #pop highest woman from m's preference list
        
        #if his top choice is unengaged then she accepts
        if b not in engagedB:
            print('m' + str(a) + '\'s current top preference w' + str(b) + ' is not engaged')
            print('match: w' + str(b) + ' : m' + str(a))

            matches.update({b : a})
            engagedA.update({a : preflist})
            engagedB.update({b : prefB.pop(b)})
        else:
            #If a is higher on preflistB than current matching then switch
            acurr = matches.get(b)
            if engagedB.get(b).index(a) < engagedB.get(b).index(acurr):
                print('m' + str(a) + '\'s current top preference w' + str(b) + ' is engaged')
                print('w' + str(b) + ' prefers m' + str(a) + ' over m' + str(acurr))
                print('unmatch: w' + str(b) + ' : m' + str(acurr))
                print('match: w' + str(b) + ' : m' + str(a))

                #Set new match
                matches[b] = a
                engagedA.update({a : preflist})

                #remove aa from engaged and put back into top of prefA
                preflistAA = engagedA.pop(a)
                prefA.put((acurr, preflistAA))
            else:
                print('m' + str(a) + '\'s current top preference w' + str(b) + ' is happily engaged')
                
                prefA.update({a : preflist})

        print('')

    return matches