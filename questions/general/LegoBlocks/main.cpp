/*
 *  You have 4 types of lego blocks, of sizes 1 * 1 * 1, 1 * 1 * 2, 1 * 1 * 3 and 1 * 1 * 4.
 *  Assume you have infinite number of blocks of each type.
 *
 *  You want to make a wall of height N and width M out of these blocks.
 *  The wall should not have any holes in it. The wall you build should be one solid
 *  structure. A solid structure means that it should not be possible to separate
 *  the wall along any vertical line without cutting any lego block used to build the wall.
 *  The blocks can only be placed horizontally. In how many ways can the wall be built?
 *
 *  Ref: http://www.hackerrank.com/challenges/lego-blocks
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt = 0;
int lego[] = {1, 2, 3};
vector<int> subset(lego, lego+3);

void loop(int n) {

	if (n > 0) {
		for (int i = 0; i < subset.size(); i++) {
			int remains = n - subset[i];
			if (remains == 0) {
				cnt++;
			} else if (remains < 0)

			loop(n);
		}
	} else {
		return;
	}
}




int main() {

	int M = 4;
	int M1 = loop(1);
	int M2 = loop(2);
	int M3 = loop(3);

	cout << M1 << " " << M2 << " " << M3 << endl;

	return 0;
}
