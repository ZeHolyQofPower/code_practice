// synthesis verilog_input_version verilog_2001
module two_mux_types(
    input a,
    input b,
    input sel_b1,
    input sel_b2,
    output wire out_assign,
    output reg out_always
); 
    // Our Mux-ses use the AND of the selectors

    // 2-1 Mux using continual assignment
    assign out_assign = (sel_b1 & sel_b2) ? b : a;
    
    // 2-1 Mux using blocking assignment
    always/*_comb*/ @(*) begin
        /*unique*/ if ((sel_b1 & sel_b2) == 1'b0) begin
            out_always = a;
        end else if ((sel_b1 & sel_b2) == 1'b1) begin 
            out_always = b;
        end
    end
endmodule