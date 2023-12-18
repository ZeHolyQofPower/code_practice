module shift_reg_three ( input clk, input d, output q );
    logic [0:0]q0_d1;
    logic [0:0]q1_d2;
    my_dff dff_instance0(.clk(clk), .d(d), .q(q0_d1));
    my_dff dff_instance1(.clk(clk), .d(q0_d1), .q(q1_d2));
    my_dff dff_instance2(.clk(clk), .d(q1_d2), .q(q));
endmodule
