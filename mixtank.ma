[top]
components : mtk@mixtank 
out : out
out : mixtankTemp_out
out : mixtankEmpty_out

in : in
in : start_in
in : mixtankControl_in
Link : in in@mtk
Link : start_in start_in@mtk
Link : mixtankControl_in mixtankControl_in@mtk

Link : out@mtk out
Link :  mixtankTemp_out@mtk mixtankTemp_out
Link : mixtankEmpty_out@mtk mixtankEmpty_out
[mtk]
 