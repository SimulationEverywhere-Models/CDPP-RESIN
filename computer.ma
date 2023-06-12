[top]
components : comp@computer 
out : out
out : mixtankControl_out
out : storetankControl_out

in : in
in : mixtankTemp_in
in : mixtankEmpty_in
in : mouldtankTemp_in
in : mouldtankEmpty_in
in : storetankEmpty_in

Link : in in@comp
Link : mixtankTemp_in mixtankTemp_in@comp
Link : mixtankEmpty_in mixtankEmpty_in@comp
Link : mouldtankTemp_in mouldtankTemp_in@comp
Link : mouldtankEmpty_in mouldtankEmpty_in@comp
Link : storetankEmpty_in storetankEmpty_in@comp

Link : out@comp out
Link : mixtankControl_out@comp   mixtankControl_out
Link : storetankControl_out@comp storetankControl_out
[comp]
 