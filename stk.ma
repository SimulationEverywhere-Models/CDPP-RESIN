[top]
components : cou@count
components : stk@storetank
in : in
in : storetankControl_in
out : out
Link : storetankControl_in storetankControl_in@stk
Link : in in@cou
Link : out@cou in@stk
Link : out@stk out
Link : out@stk done@cou
[cou]

[stk]
 