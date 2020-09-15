#include <iostream>

using namespace std;

int globalX, globalY, globalZ;


void genCoordinates()
{
	for (int x = 0; x < globalX; x++)
	{
		cout << "x" << x << " " << x << ";" << endl;
	}
	for (int y = 0; y < globalY; y++)
	{
		cout << "y" << y << " " << y << ";" << endl;
	}
	for (int z = 0; z < globalZ; z++)
	{
		cout << "z" << z << " " << z << ";" << endl;
	}
	cout << endl;
}


void genDimensions()
{
	for (int x = 1; x < globalX; x++)
	{
		cout << "nx" << x << " 1;" << endl;
	}
	for (int y = 1; y < globalY; y++)
	{
		cout << "ny" << y << " 1;" << endl;
	}
	for (int z = 1; z < globalZ; z++)
	{
		cout << "nz" << z << " 1;" << endl;
	}
	cout << endl;
}


void genGradings()
{
	for (int x = 1; x < globalX; x++)
	{
		cout << "gx" << x << " 1;" << endl;
	}
	for (int y = 1; y < globalY; y++)
	{
		cout << "gy" << y << " 1;" << endl;
	}
	for (int z = 1; z < globalZ; z++)
	{
		cout << "gz" << z << " 1;" << endl;
	}
	cout << endl;
}

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
				cout << "    name v."
					 << "x" << x << "y" << y << "z" << z
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
				cout << "    name b."
					 << "x" << x << "y" << y << "z" << z
					 << " hex"
					 << " ("
						 << " v." << "x" << x   << "y" << y   << "z" << z
						 << " v." << "x" << x+1 << "y" << y   << "z" << z
						 << " v." << "x" << x+1 << "y" << y+1 << "z" << z
						 << " v." << "x" << x   << "y" << y+1 << "z" << z
						 << " v." << "x" << x   << "y" << y   << "z" << z+1
						 << " v." << "x" << x+1 << "y" << y   << "z" << z+1
						 << " v." << "x" << x+1 << "y" << y+1 << "z" << z+1
						 << " v." << "x" << x   << "y" << y+1 << "z" << z+1
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
	if (name == "west")
	{
 		for (int z = 0; z < globalZ-1; z++)
 		{
 			for (int y = 0; y < globalY-1; y++)
 			{
					cout << "            "
						 << "("
						 << " v." << "x" << "0" << "y" << y   << "z" << z
						 << " v." << "x" << "0" << "y" << y+1 << "z" << z
						 << " v." << "x" << "0" << "y" << y+1 << "z" << z+1
						 << " v." << "x" << "0" << "y" << y   << "z" << z+1
						 << " )"
						 << endl;
 			}
 		}
	}
	else if (name == "east")
	{
 		for (int z = 0; z < globalZ-1; z++)
 		{
 			for (int y = 0; y < globalY-1; y++)
 			{
					cout << "            "
						 << "("
							 << " v." << "x" << globalX-1 << "y" << y   << "z" << z
							 << " v." << "x" << globalX-1 << "y" << y+1 << "z" << z
							 << " v." << "x" << globalX-1 << "y" << y+1 << "z" << z+1
							 << " v." << "x" << globalX-1 << "y" << y   << "z" << z+1
						 << " )"
						 << endl;
 			}
 		}
	}
	else if (name == "south")
	{
 		for (int z = 0; z < globalZ-1; z++)
 		{
 			for (int x = 0; x < globalX-1; x++)
 			{
					cout << "            "
						 << "("
							 << " v." << "x" << x   << "y" << "0" << "z" << z
							 << " v." << "x" << x+1 << "y" << "0" << "z" << z
							 << " v." << "x" << x+1 << "y" << "0" << "z" << z+1
							 << " v." << "x" << x   << "y" << "0" << "z" << z+1
						 << " )"
						 << endl;
 			}
 		}
	}
	else if (name == "north")
	{
 		for (int z = 0; z < globalZ-1; z++)
 		{
 			for (int x = 0; x < globalX-1; x++)
 			{
					cout << "            "
						 << "("
							 << " v." << "x" << x   << "y" << globalY-1 << "z" << z
							 << " v." << "x" << x+1 << "y" << globalY-1 << "z" << z
							 << " v." << "x" << x+1 << "y" << globalY-1 << "z" << z+1
							 << " v." << "x" << x   << "y" << globalY-1 << "z" << z+1
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
							 << " v." << "x" << x   << "y" << y   << "z" << "0"
							 << " v." << "x" << x+1 << "y" << y   << "z" << "0"
							 << " v." << "x" << x+1 << "y" << y+1 << "z" << "0"
							 << " v." << "x" << x   << "y" << y+1 << "z" << "0"
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
							 << " v." << "x" << x   << "y" << y   << "z" << globalZ-1
							 << " v." << "x" << x+1 << "y" << y   << "z" << globalZ-1
							 << " v." << "x" << x+1 << "y" << y+1 << "z" << globalZ-1
							 << " v." << "x" << x   << "y" << y+1 << "z" << globalZ-1
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
		genBoundary("west",   "patch"); // x = xmin;
		genBoundary("east",   "patch"); // x = xmax;
		genBoundary("south",  "patch"); // y = ymin;
		genBoundary("north",  "patch"); // y = ymax;
		genBoundary("bottom", "patch"); // z = zmin;
		genBoundary("top",    "patch"); // z = zmax;
		genBoundary("wall",   "patch");
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

	genCoordinates();
	
	genDimensions();
	
	genGradings();

    genVertices();

    genBlocks();

    genEdges();

    genBoundaries();

    return 0;
}

