# Key Concepts of OS
- Abstraction
- Protection
- Illusion
- Coordination anad Optimization

## Abstraction
In general, Abstraction means picking out only key features to reduce complexity.
<br>
In the context of OS, it __hides hardware complexity__ and provide a clean, uniform, and standard __interface__ to programmers. It is usually called Application Programming Interfaces(API)

For example, we want to display "Hello World"" on the screen. Without OS, we need to know how the hardware on the screen is configured and how to control it. Based on that, you have to make letters by dotting the screen in pixels. However, between the complex hardware and applications of devices such as screens, the OS replaces these complex tasks with simple api like printf(). So programmers can print "Hello World" in seconds by running the function with some parameters.
<br>
OS is a huge library that offers a variety of functions in terms of providing these program interfaces.

System calls provide the interface between application SW and the operating system. 
<br>
(Application) --> (C Library) --> (Kernel)
<br>
Library functions are connected with specific functions in system call.
