//program for half adder
module sum1(input wire a,b, output wire s);
    assign s= a^b;
endmodule

module carry1(input wire a,b, output wire c);
    assign c= a&b;
endmodule


