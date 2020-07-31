#include <iostream>

using namespace std;

int globalX, globalY, globalZ;


void genVertices()
{
	cout << "vertices" << endl;
	cout << "(" << endl;
	for (int z = 0; z < globalZ; z++)
	{
		for (int y = 0; y < globalY; y++)
		{
			for (int x = 0; x < globalX; x++)
			{
				cout << "    name v"
					 << x << y << z
					 << " ("
						 << " $x" << x
						 << " $y" << y
						 << " $z" << z 
					 << " )"
					 << endl;
			}
		}
	}
	cout << ");" << endl;
	cout << endl;
}


void genBlocks()
{
	cout << "blocks" << endl;
	cout << "(" << endl;
	for (int z = 0; z < globalZ - 1; z++)
	{
		for (int y = 0; y < globalY - 1; y++)
		{
			for (int x = 0; x < globalX - 1; x++)
			{
				cout << "    name b"
					 << x << y << z
					 << " hex"
					 << " ("
						 << " v" << x   << y   << z
						 << " v" << x+1 << y   << z
						 << " v" << x+1 << y+1 << z
						 << " v" << x   << y+1 << z
						 << " v" << x   << y   << z+1
						 << " v" << x+1 << y   << z+1
						 << " v" << x+1 << y+1 << z+1
						 << " v" << x   << y+1 << z+1
					 << " )"
					 << " ("
					 	<< " $nx" << x+1
					 	<< " $ny" << y+1
					 	<< " $nz" << z+1
					 << " )"
					 << " simpleGrading"
					 << " ("
					 	<< " $gx" << x+1
					 	<< " $gy" << y+1
					 	<< " $gz" << z+1
					 << " )"
					 << endl;
			}
		}
	}
	cout << ");" << endl;
	cout << endl;
}


void genEdges()
{
}


void genBoundary(string name, string type)
{
	cout << "    " << name << endl;
	cout << "    {" << endl;
	cout << "        type " << type << ";" << endl;
	cout << "        faces" << endl;
	cout << "        (" << endl;
	if (name == "inlet")
	{
 		for (int z = 0; z < globalZ-1; z++)
 		{
 			for (int y = 0; y < globalY-1; y++)
 			{
					cout << "            "
						 << "("
						 << " v" << "0" << y   << z
						 << " v" << "0" << y+1 << z
						 << " v" << "0" << y+1 << z+1
						 << " v" << "0" << y   << z+1
						 << " )"
						 << endl;
 			}
 		}
	}
	else if (name == "outlet")
	{
 		for (int z = 0; z < globalZ-1; z++)
 		{
 			for (int y = 0; y < globalY-1; y++)
 			{
					cout << "            "
						 << "("
							 << " v" << globalX-1 << y   << z
							 << " v" << globalX-1 << y+1 << z
							 << " v" << globalX-1 << y+1 << z+1
							 << " v" << globalX-1 << y   << z+1
						 << " )"
						 << endl;
 			}
 		}
	}
	else if (name == "left")
	{
 		for (int z = 0; z < globalZ-1; z++)
 		{
 			for (int x = 0; x < globalX-1; x++)
 			{
					cout << "            "
						 << "("
							 << " v" << x   << "0" << z
							 << " v" << x+1 << "0" << z
							 << " v" << x+1 << "0" << z+1
							 << " v" << x   << "0" << z+1
						 << " )"
						 << endl;
 			}
 		}
	}
	else if (name == "right")
	{
 		for (int z = 0; z < globalZ-1; z++)
 		{
 			for (int x = 0; x < globalX-1; x++)
 			{
					cout << "            "
						 << "("
							 << " v" << x   << globalY-1 << z
							 << " v" << x+1 << globalY-1 << z
							 << " v" << x+1 << globalY-1 << z+1
							 << " v" << x   << globalY-1 << z+1
						 << " )"
						 << endl;
 			}
 		}
	}
	else if (name == "bottom")
	{
 		for (int y = 0; y < globalY-1; y++)
 		{
 			for (int x = 0; x < globalX-1; x++)
 			{
					cout << "            "
						 << "("
							 << " v" << x   << y   << "0"
							 << " v" << x+1 << y   << "0"
							 << " v" << x+1 << y+1 << "0"
							 << " v" << x   << y+1 << "0"
						 << " )"
						 << endl;
 			}
 		}
	}
	else if (name == "top")
	{
 		for (int y = 0; y < globalY-1; y++)
 		{
 			for (int x = 0; x < globalX-1; x++)
 			{
					cout << "            "
						 << "("
							 << " v" << x   << y   << globalZ-1
							 << " v" << x+1 << y   << globalZ-1
							 << " v" << x+1 << y+1 << globalZ-1
							 << " v" << x   << y+1 << globalZ-1
						 << " )"
						 << endl;
 			}
 		}
	}
	else
	{
		/* code */
	}
	cout << "        );" << endl;
	cout << "    }" << endl;
}

void genBoundaries()
{	cout << "boundary" << endl;
	cout << "(" << endl;
		genBoundary("inlet", "patch");
		genBoundary("outlet", "patch");
		genBoundary("left", "empty");
		genBoundary("right", "empty");
		genBoundary("bottom", "wall");
		genBoundary("top", "patch");
		genBoundary("floatingObject", "wall");
	cout << ");" << endl;
	cout << endl;
}


int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		cout << "Usage: blockMeshHelper <x> <y> <z>" << endl;

		return 1;
	}

	globalX = stoi(argv[1]);
	globalY = stoi(argv[2]);
	globalZ = stoi(argv[3]);

    genVertices();

    genBlocks();

    genEdges();

    genBoundaries();

    return 0;
}

