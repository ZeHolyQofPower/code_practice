// synthesis verilog_input_version verilog_2001
module priority_encoder_eight_bit (
    input [7:0] in,
    output reg [2:0] pos
);
    always @(*) begin
        casez (in)
            8'bzzzz_zzz1: pos = 3'd0;
            8'bzzzz_zz10: pos = 3'd1;
            8'bzzzz_z100: pos = 3'd2;
            8'bzzzz_1000: pos = 3'd3;
            8'bzzz1_0000: pos = 3'd4;
            //TODO
            8'b0000_0000: pos = 3'd0e
        endcase
    end
endmodule