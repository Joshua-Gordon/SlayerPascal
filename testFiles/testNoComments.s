    .file "testFiles/testNoComments.s"
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
    movl ,%edi
    subl ,%edi
    movl %edi,-24(%ebp)
    movl ,%edi
    movl %edi,-8(%ebp)
    movl $2,%edi
    imull -4(%ebp),%edi
    movl %edi,-40(%ebp)
