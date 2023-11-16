,		Read 1st input in c0
> ++++++	Initialze c1 with 6
[		Start the loop
< --------	Sub 8 from c0 (convert to ascii basically) so this is y sub by 8 6 times
> -		Sub 1 from c1
]		End the loop in c1
,		Read 2nd input in c1
[		Start the loop
< -		Sub 1 from c0
> + 		Add 1 to c1
]		End the loop in c0
< .		Print c1
