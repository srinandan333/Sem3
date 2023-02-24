//program for full adder
module sum1(input wire a,b,c, output wire s);
    assign s=a^b^c;
endmodule

module carry1(input wire a,b,c, output wire z);
    assign z=(a&b)|(b&c)|(c&a);
endmodule