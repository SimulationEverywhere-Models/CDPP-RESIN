[top]
components : Stank
components : mtk@mixtank
components : motk@mouldtank
Out : out
out : storetankEmpty_out
out : mixtankTemp_out
out : mixtankEmpty_out
out : mouldtankTemp_out
out : mouldtankEmpty_out
in : start_in
in : mixtankControl_in
in : storetankControl_in
In : in

Link : in in@stank
Link : start_in     start_in@mtk 
Link : start_in     start_in@motk 
Link : storetankControl_in storetankControl_in@stank
Link :  mixtankControl_in  mixtankControl_in@mtk

Link : out@stk in@mtk
Link : out@mtk in@motk
Link : out@motk out
Link : out@stank      storetankEmpty_out 
Link : mixtankTemp_out@mtk         mixtankTemp_out 
Link : mixtankEmpty_out@mtk        mixtankEmpty_out 
Link : mouldtankTemp_out@motk       mouldtankTemp_out 
Link : out@motk                    mouldtankEmpty_out 
[mtk]
[motk]
[Stank]
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
 