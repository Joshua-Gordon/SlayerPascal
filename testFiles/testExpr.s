    .file "testFiles/testExpr.s"
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
    movl $7,%edi
    movl %edi,-12(%ebp)
    movl $3,%edi
    movl %edi,-8(%ebp)
    movl -12(%ebp),%edi
    movl -8(%ebp),%esi
    imull $7,%esi
    addl %edi,%esi
    addl -8(%ebp),%edi
    movl -12(%ebp),%esi
    idivl -8(%ebp),%esi
    subl %edi,%esi
    movl %edi,-4(%ebp)
