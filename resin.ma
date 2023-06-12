[top]
components : controlsystem
components : prodline
out : out
in : in
Link : in in@controlsystem 
Link : in in@prodline
Link : storetankEmpty_out@prodline			storetankEmpty_in@controlsystem
Link : mixtankTemp_out@prodline				mixtankTemp_in@controlsystem
Link : mixtankEmpty_out@prodline			mixtankEmpty_in@controlsystem
Link : mouldtankTemp_out@prodline			mouldtankTemp_in@controlsystem
Link : mouldtankEmpty_out@prodline			mouldtankEmpty_in@controlsystem
Link : out@controlsystem					start_in@prodline
Link : storetankControl_out@controlsystem	storetankControl_in@prodline
Link : mixtankControl_out@controlsystem		mixtankControl_in@prodline
Link : out@prodline out

[controlsystem]
components : compu@Computer
in : in
in : storetankEmpty_in
in : mixtankTemp_in
in : mixtankEmpty_in
in : mouldtankTemp_in
in : mouldtankEmpty_in
out : out
out : mixtankControl_out
out : storetankControl_out
Link : in							in@compu
Link : storetankEmpty_in			storetankEmpty_in@compu
Link : mixtankTemp_in				 mixtankTemp_in@compu
Link : mixtankEmpty_in				mixtankEmpty_in@compu
Link : mouldtankTemp_in				mouldtankTemp_in@compu
Link : mouldtankEmpty_in			mouldtankEmpty_in@compu
Link : out@compu					out
Link : storetankControl_out@compu	storetankControl_out
Link : mixtankControl_out@compu		mixtankControl_out
[compu]

[prodline]
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
Link : start_in						start_in@mtk 
Link : start_in						start_in@motk 
Link : storetankControl_in			storetankControl_in@stank
Link :  mixtankControl_in			mixtankControl_in@mtk

Link : out@stk						in@mtk
Link : out@mtk						in@motk
Link : out@motk						out
Link : out@stank					storetankEmpty_out 
Link : mixtankTemp_out@mtk			mixtankTemp_out 
Link : mixtankEmpty_out@mtk			mixtankEmpty_out 
Link : mouldtankTemp_out@motk       mouldtankTemp_out 
Link : out@motk						mouldtankEmpty_out 
[mtk]
[motk]

[Stank]
components : cou@count
components : stk@storetank
in : in
in : storetankControl_in
out : out
Link : storetankControl_in	storetankControl_in@stk
Link : in					in@cou
Link : out@cou				in@stk
Link : out@stk				out
Link : out@stk				done@cou
[cou]
[stk]
 