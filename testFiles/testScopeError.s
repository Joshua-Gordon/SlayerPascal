    .file "testFiles/testScopeError.s"
.section      .rodata
.LLC0:
  .string "%d"
.LLC1:
  .string "%d"
.LLD0:
  .string "%f"
.LLD1:
  .string "%f
"
.section      ".text"
          .globl main
          .type main,@function
main:
          pushl %ebp
          movl %esp,%ebp
          subl $8,%esp
          andl $-16,%esp
          movl $0,%eax
          subl %eax,%esp
          call bones
          leave     
          ret       
.LLfe0:
          .size main, .LLfe0-main
bones:
    movl $4,%edi
    movl %edi,-4(%ebp)
