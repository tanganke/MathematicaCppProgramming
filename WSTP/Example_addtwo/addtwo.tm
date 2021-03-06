:Begin:
:Function:       addtwo
:Pattern:        AddTwo[i_Integer, j_Integer]
:Arguments:      { i, j }
:ArgumentTypes:  { Integer, Integer }
:ReturnType:     Integer
:End:

:Evaluate: AddTwo::usage = "AddTwo[x, y] gives the sum of two machine integers x and y."

int addtwo( int i, int j)
{
	return i+j;
}