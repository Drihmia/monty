,> ,> +++ +++			Read 1st and 2nd input in #0; #1 respectively and initialize #2 by 6

[				The following loop converts the 2 inputs from binary
	<< ---- ----
	> ---- ----
	> -
]				Loop ends in #2
<<				Move to #0
[
	> [ > + > + << -]	Copy #1 in #2 and #3; Loop ends in #1
	> [< + > -]		Retain #1 value; Loop ends in #2
	<< -			Decrement #0
]				Loop ends in #0
++++ ++++			Set #0 to 8
[				The following loop basically converts cell 3 to binary
	>>> +++ +++
	<<< -
]				Loop ends in #0
>>> .				Output #3
