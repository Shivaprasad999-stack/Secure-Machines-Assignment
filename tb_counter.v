`timescale 1ns/1ps

module tb_counter;

    reg clk;
    reg reset;
    wire [3:0] led;

    // Instantiate the counter
    counter_4bit uut (
        .clk(clk),
        .reset(reset),
        .led(led)
    );

    // Clock generation: 100 MHz -> 10 ns period
    initial clk = 0;
    always #5 clk = ~clk; // Toggle every 5 ns

    // Test sequence
    initial begin
        reset = 1;       // Apply reset
        #20;
        reset = 0;       // Release reset
        #500;            // Run simulation long enough to see increments
        $finish;
    end

endmodule
