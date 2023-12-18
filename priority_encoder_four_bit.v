// synthesis verilog_input_version verilog_2001
module priority_encoder_four_bit (
    input [3:0] in,
    output /*logic*/ reg [1:0] pos
);
    // "...cascaded ternary structures... preferred way of representing priority encoders 
    // as they are a more readable representation..."
    // From the lowRISC style guide, subsection #case-statements

    // 4bit Priority Encoder that finds position of least significant high bit.
    /*
    assign pos = 
        (in == 4'bxxx1) ? 2'd0 :
        (in == 4'bxx10) ? 2'd1 :
        (in == 4'bx100) ? 2'd2 :
        (in == 4'b1000) ? 2'd3 : 2'd0 ;
    */
    // They used a different type so I can't use this cascading ternary.
    /*always_comb begin
        priority case (in)
            4'bxxx1: pos = 2'd0;
            4'bxx10: pos = 2'd1;
            4'bx100: pos = 2'd2;
            4'b1000: pos = 2'd3;
            4'b0000: pos = 2'd0;
        endcase
    end*/
    // You can't use wildcard comparisons in pure Verilog2001 😠
    always @(*) begin
        case (in)
            //4'bxxx1: pos = 2'd0;
            4'b0001: pos = 2'd0;
            4'b0011: pos = 2'd0;
            4'b0101: pos = 2'd0;
            4'b0111: pos = 2'd0;
            4'b1001: pos = 2'd0;
            4'b1011: pos = 2'd0;
            4'b1101: pos = 2'd0;
            4'b1111: pos = 2'd0;
            //4'bxx10: pos = 2'd1;
            4'b0010: pos = 2'd1;
            4'b0110: pos = 2'd1;
            4'b1010: pos = 2'd1;
            4'b1110: pos = 2'd1;
            //4'bx100: pos = 2'd2;
            4'b0100: pos = 2'd2;
            4'b1100: pos = 2'd2;
            4'b1000: pos = 2'd3;
            4'b0000: pos = 2'd0;
        endcase
    end
endmodule