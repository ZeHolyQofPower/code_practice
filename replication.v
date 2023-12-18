module replication (
    input a, b, c, d, e,
    output [24:0] out );//

    
    logic [24:0]top_vector;
    assign top_vector = { {5{a}}, {5{b}}, {5{c}}, {5{d}}, {5{e}} };
    logic [24:0]bottom_vector;
    assign bottom_vector = { {5{a, b, c, d, e}} };
    // The output is XNOR of two vectors created by 
    // concatenating and replicating the five inputs.
    assign out = ~{top_vector} ^ {bottom_vector};

endmodule
