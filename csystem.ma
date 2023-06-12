[top]
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

Link : in in@compu
Link : storetankEmpty_in storetankEmpty_in@compu
Link : mixtankTemp_in    mixtankTemp_in@compu
Link : mixtankEmpty_in  mixtankEmpty_in@compu
Link : mouldtankTemp_in  mouldtankTemp_in@compu
Link : mouldtankEmpty_in mouldtankEmpty_in@compu
Link : out@compu   out
Link : storetankControl_out@compu storetankControl_out
Link : mixtankControl_out@compu mixtankControl_out
[compu]