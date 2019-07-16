**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Start, Ready, Running, Waiting, Terminated/Exit

Start - the initial state when a process is first started/created.

Ready - the process is waiting to be assigned to a processer. Ready processes are waiting to have the processor allocated to them by the operating system so they can run. 

Running - Once the process has been assigned to a processor by the OS scheduler, the process state is set to running and the processor executes its instructions.

Waiting - Process moves into the waiting state if it needs to wait for a resource, such as waiting for user input, or waiting for a file to become available.

Terminated/Exit - Once the process finishes its execution, or it is terminated by the operating system, it is moved to the terminated state where it waits to be removed from main memory.



**2. What is a zombie process?**

a process that has completed execution (via the exit system call) but still has an entry in the process table: it is a process in the "Terminated state".



**3. How does a zombie process get created? How does one get destroyed?**

This occurs for child processes, where the entry is still needed to allow the parent process to read its child's exit status: once the exit status is read via the wait system call, the zombie's entry is removed from the process table and it is said to be "reaped". A child process always first becomes a zombie before being removed from the resource table. In most cases, under normal system operation zombies are immediately waited on by their parent and then reaped by the system – processes that stay zombies for a long time are generally an error and cause a resource leak.



**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled language benefits:
Faster performance by directly using the native code of the target machine
Opportunity to apply quite powerful optimisations during the compile stage

Interpreted language benefits:
Easier to implement
No need to run a compilation stage: can execute code directly "on the fly"
Can be more convenient for dynamic languages






