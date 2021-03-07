:Evaluate:      SayHello::usage="SayHello[] gives string \"Hello WSTP\""

:Begin:
:Function:      say_hello
:Pattern:       SayHello[]
:Arguments:     {}
:ArgumentTypes: {}
:ReturnType:    String
:End:

:Evaluate:      ReverseList::usage="ReverseList[list] gives Reverse[list]"

:Begin:
:Function:      reverse_list
:Pattern:       ReverseList[list:{___Integer}]
:Arguments:     {list}
:ArgumentTypes: {IntegerList}
:ReturnType:    Manual
:End:

:Begin:
:Function:      reverse_list
:Pattern:       ReverseList[list:{___Real}]
:Arguments:     {list}
:ArgumentTypes: {RealList}
:ReturnType:    Manual
:End:
