module byte_shift_reg_three ( 
    input clk, 
    input [7:0] d, 
    input [1:0] sel, 
    output [7:0] q 
);
    // 8bit D-FFs are chained to create a shift register of length three.
    logic [7:0]q0_d1;
    logic [7:0]q1_d2;
    logic [7:0]q2;
    my_dff8 dff_instance0(.clk(clk), .d(d), .q(q0_d1));
    my_dff8 dff_instance1(.clk(clk), .d(q0_d1), .q(q1_d2));
    my_dff8 dff_instance2(.clk(clk), .d(q1_d2), .q(q2));
    // 4-1 Mux for each intermediate value.
    always_comb begin
        unique case (sel)
            2'b00: q = d;
            2'b01: q = q0_d1;
            2'b10: q = q1_d2;
            2'b11: q = q2;
            default: q = d;
        endcase
    end
endmodule