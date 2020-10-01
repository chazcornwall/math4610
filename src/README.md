** Update math4610lib.a **

1. <pre><code> g++ -c *.cpp </code></pre>
2. <pre><code> ar rcv math4610lib.a *.o </code></pre>


** Compile with math4610lib.a **

<pre><code> g++ <file>.cpp <directory to math4610lib.a>/math4610lib.a -o <file>.exe </code></pre>
