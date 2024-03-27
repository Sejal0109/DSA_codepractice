// File: furthest_building_you_can_reach.cpp

/*
    Leetcode Link: https://leetcode.com/problems/furthest-building-you-can-reach/description/
*/

/*
    Problem Statement:
    You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
    You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
    While moving from building i to building i+1 (0-indexed),
        If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
        If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
    Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

    Note:
    Every building is reachable if you use your ladders and bricks optimally.
*/

#include <vector>
#include <queue>

using namespace std;

class Solution { 
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n = h.size();
        int remBrick = b, remLadder = l;
        int stoppingIdx = 0;
        int flag = 0; // flag to check if we traversed all buildings, or did we stop somewhere

        priority_queue<int> pq; // max heap => we'll store upDiff in this, for whenever bricks are consumed
        for(int i = 0; i < n-1; i++) {
            if(h[i+1] <= h[i]) { // no up movement required, continue
                continue;
            } else { // up movement required
                int currGap = h[i+1] - h[i]; // upDiff
                if(currGap <= remBrick) { // we'll use bricks and save ladders
                    remBrick -= currGap;
                    pq.push(currGap);
                } else { // now we cant use bricks to move forward
                    if(!pq.empty()) {
                        int prevMaxGap = pq.top();
                        if(prevMaxGap > currGap && remLadder > 0) { // suppose currMaxGap is 100, upDiff right now is 25 so we can retirve bricks 
                        // use them at upDiff, and where we used currMaxGap bricks, there we can use one ladder.
                            pq.pop(); // since we use ladder for prevMaxGap, we remove it from pq
                            remLadder--;
                            remBrick += prevMaxGap - currGap; // bricks retrived would be 75, since 25 spent now, also push in pq
                            pq.push(currGap);
                        } else {
                            if(remLadder > 0) {
                                // for case like: prevMaxGap = 25, currGap = 80, here, we wont retrive back bricks and use here
                                // here we will directly use ladder
                                remLadder--; 
                            } else { // no ladder left, remBricks cant help to get up, prevMaxGap is lesser than this currGap,
                            // so we also cant retrieve older bricks, in this case, we need to stop
                                stoppingIdx = i;
                                flag = 1;
                                break;
                            }
                        }
                    } else { // when pq is empty, no gap stored for upDiff consuming bricks
                    // case like: bricks from start => 10, currGap is 100, we cant travel using bricks, we need to use ladder
                        if(remLadder > 0) {
                            remLadder--;
                        } else {
                            stoppingIdx = i;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }

        return flag == 1 ? stoppingIdx : n-1; // return last index, as it traversed all buildings if flag remains 0
    }
};
