// program for basic gates
module not1(input wire i0, output wire o1);
	assign o1= ~i0;
endmodule

module and2(input wire i0, i1, output wire o2);
	assign o2= i0&i1;
endmodule

module or2(input wire i0, i1, output wire o3);
	assign o3= i0|i1;
endmodule

module xor2(input wire i0, i1, output wire o4);
	assign o4= i0^i1;
endmodule

