//program for ripple carry adder
module fulladder(input wire a,b, cin, output wire sum, cout);
	assign sum=(a^b^cin);
	assign cout=(a&b)|(b&cin)|(cin&a);
endmodule

module rcadder(input wire [3:0] a,b, input wire cin, output wire [3:0] s, output wire cout);
wire c0,c1,c2;
fulladder f_0(a[0],b[0],cin,s[0],c0);
fulladder f_1(a[1],b[1],c0,s[1],c1);
fulladder f_2(a[2],b[2],c1,s[2],c2);
fulladder f_3(a[3],b[3],c2,s[3],cout);
endmodule
