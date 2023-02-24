//program for arithmetic logic unit
module fa(input wire i0,i1,cin,output wire cout,sum);
wire t0,t1,t2;
xor3 a1(i0,i1,cin,sum);
and2 a2(i0,i1,t0);
and2 a3(i1,cin,t1);
and2 a4(i0,cin,t2);
or3 a5(t0,t1,t2,cout);
endmodule

module addsub(input wire i0,i1,addsub,cin,output wire cout,sumdiff);
wire t;
fa a1(i0,t,cin,cout,sumdiff);
xor2 a2(i1,addsub,t);
endmodule

module alu_slice(input wire [1:0]op,input wire i0,i1,cin,output wire cout,o);
wire t_and,t_or,t_andor,t_sumdiff;
addsub a1(i0,i1,op[0],cin,cout,t_sumdiff);
and2 a2(i0,i1,t_and);
or2 a3(i0,i1,t_or);
mux2 a4(t_and,t_or,op[0],t_andor);
mux2 a5(t_andor,t_sumdiff,op[1],o);
endmodule

module alu (input wire [1:0] op, input wire [15:0] i0, i1,output wire [15:0] o, output wire cout);
wire [14:0]c;
alu_slice a1(op,i0[0],i1[0],op[0],c[0],o[0]);
alu_slice a2(op,i0[1],i1[1],c[0],c[1],o[1]);
alu_slice a3(op,i0[2],i1[2],c[1],c[2],o[2]);
alu_slice a4(op,i0[3],i1[3],c[2],c[3],o[3]);
alu_slice a5(op,i0[4],i1[4],c[3],c[4],o[4]);
alu_slice a6(op,i0[5],i1[5],c[4],c[5],o[5]);
alu_slice a7(op,i0[6],i1[6],c[5],c[6],o[6]);
alu_slice a8(op,i0[7],i1[7],c[6],c[7],o[7]);
alu_slice a10(op,i0[8],i1[8],c[7],c[8],o[8]);
alu_slice a11(op,i0[9],i1[9],c[8],c[9],o[9]);
alu_slice a12(op,i0[10],i1[10],c[9],c[10],o[10]);
alu_slice a13(op,i0[11],i1[11],c[10],c[11],o[11]);
alu_slice a14(op,i0[12],i1[12],c[11],c[12],o[12]);
alu_slice a15(op,i0[13],i1[13],c[12],c[13],o[13]);
alu_slice a16(op,i0[14],i1[14],c[13],c[14],o[14]);
alu_slice a17(op,i0[15],i1[15],c[14],cout,o[15]);
endmodule
