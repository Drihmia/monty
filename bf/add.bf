, > , > +++ +++		# Read 2 intergers in c0 c1 and initialize c2 by 6
[			# Loop start 
	<< ---- ----	# Sub 8 from c0
	> ---- ----	# Sub 8 from c1
	> -		# Decrement pointer counter (c2)
]			# Loop ends in c2
<			# Move pointer to c1
[			# Loop start
	< +		# Increment c0
	> -		# Decrement c1
]			# Loop end in c1
++++ ++++		# Assign 8 to c1 (loop counter)
[			# Loop start
	< +++ +++	# Increment c0 by 6 (to get ascci)
	> -		# Decrement c1
]			# Loop ends in c1
< .			# Output c0
