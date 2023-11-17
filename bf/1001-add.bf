,		Read 1st input in c0
> ++++++	Initialze c1 with 6
[		Start the loop
< --------	Sub 8 from c0 (convert to ascii basically)
> -		Sub 1 from c1
]		End the loop in c1
,		Read 2nd input in c1
[		Start the loop at c1
< + > -		Move data pointer to c0 increment it; move left to c1 decrement
]		End the loop in c0
< .		Print c1
