Power Quality Waveform Analyser

Author: Alan John - 24019014
GitHub Repository https://github.com/alan2john/UWE-Programming-for-engineers-coursework.git

Description
This is a modular C program designed to parse and analyse real-world industrial power quality data from a CSV log. It computes True RMS, peak-to-peak amplitude, 
DC offset and flags sensor clipping and tolerance compliance (±10% of nominal 230V) for a 3-phase system.

How to Compile and Run

Using CLion (CMake)
1. Open the project folder in CLion.
2. Ensure the CMakeLists.txt file is loaded.
3. Click the build (Hammer) icon.
4. Click the run (Play) icon. 
5. The program will output the final analysis to results.txt.


To run the compiled executable:
Windows: .\PowerAnalyser.exe
