#include<iostream>
#include<string>

using namespace std;

int main() {

	int y=0;
	int x=0;

	int direction = 1 ;
	//upwards=1
	//Right =2
	//downwards=3
	//Left=4
	string input="FxLxLxFx";
	int home=0;

	for (int counter = 0; counter < input.size(); counter++)
	{

		switch (input.at(counter))
		{
		case 'R':
			direction++;
			if (direction == 5)direction = 1;
			
			break;
		case 'L':
			direction--;
			if (direction == 0)direction = 4;

			break;

		case 'F':
			if (direction == 1)y++;
			if (direction == 2)x++;
			if (direction == 3)y--;
			if (direction == 4)x--;


		default:
			break;
		}

	}
	cout << "y= " << y << " x= " << x <<endl;

	//returning to base 

	while (x != 0 || y != 0) {

		switch (direction) {

		case 1:
			if (y < 0) {
				home -= y;
				y = 0;
			}
			if (x < 0) {
				direction = 2;
				home += 1;
			}
			if (x > 0) {
				direction = 4;
				home += 1;
			}
			if (y > 0 && x==0) {
				home = home + y + 2;
				y = 0;
			}
			break;

		case 2:
			if (x < 0) {
				home -= x;
				x = 0;
			}
			if (y < 0) {
				direction = 1;
				home += 1;
			}
			if (y > 0) {
				direction = 3;
				home += 1;
			}
			if (x > 0 && y == 0) {
				home = home + x + 2;
				x = 0;
			}
			break;

		case 3:
			if (y > 0) {
				home += y;
				y = 0;
			}
			if (x < 0) {
				direction = 2;
				home += 1;
			}
			if (x > 0) {
				direction = 4;
				home += 1;
			}
			if (y < 0 && x == 0) {
				home = home + (y*-1) + 2;
				y = 0;
			}
			break;

		case 4:
			if (x > 0) {
				home += x;
				x = 0;
			}
			if (y < 0) {
				direction = 1;
				home += 1;
			}
			if (y > 0) {
				direction = 3;
				home += 1;
			}
			if (x < 0 && y == 0) {
				home = home + (x*-1) + 2;
				x = 0;
			}
			break;




		}


	}
	cout << home;
	return 0;
}