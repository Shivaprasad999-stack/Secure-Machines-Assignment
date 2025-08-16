`timescale 1ns/1ps
module tb_counter;

  reg clk = 0;
  reg reset;
  wire [3:0] led;

  // Instantiate counter with small divider
  counter_4bit #(.DIV_CYCLES(16)) uut (
    .clk(clk),
    .reset(reset),
    .led(led)
  );

  // Clock: 100 MHz -> 10 ns period
  always #5 clk = ~clk;

  // Reset sequence
  initial begin
    reset = 1;
    #20;
    reset = 0;
  end

  // Run time
  initial begin
    #500;   // run 500 ns
    $stop;
  end

endmodule

