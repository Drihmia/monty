# Stacks, Queues - LIFO, FIFO

Basically the first part of this project implements the `stack` (Last In First Out) and the `queue` (First In First Out) to create an iterpreter for `Monty` language, and the second part perform some tasks in `brainf*ck` language.

## Data structure

```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

```

## The Monty language

<figure>
    <img src="https://drive.google.com/uc?export=view&id=16-g07Qw2QdPFVIo-K0IJbr5FoxFR9Uff" alt="monty language stack, queue">
</figure>

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Brainf**k

<figure>
    <img src="https://drive.google.com/uc?export=view&id=1XkAmQ0h2Rit8R9Xqr3C06PTVNlsduvEJ" alt="brainfuck language">
</figure>

Brainfuck is an esoteric programming language created in 1993 by Urban Müller.  
Notable for its extreme minimalism, the language consists of only eight simple commands, a data pointer and an instruction pointer. While it is fully Turing complete, it is not intended for practical use, but to challenge and amuse programmers. Brainfuck requires one to break commands into microscopic steps.
The language's name is a reference to the slang term brainfuck, which refers to things so complicated or unusual that they exceed the limits of one's understanding, as it was not meant or made for designing actual software but to challenge the boundaries of computer programming.

### Language design

The language consists of eight commands. A brainfuck program is a sequence of these commands, possibly interspersed with other characters (which are ignored). The commands are executed sequentially, with some exceptions: an instruction pointer begins at the first command, and each command it points to is executed, after which it normally moves forward to the next command. The program terminates when the instruction pointer moves past the last command.

The brainfuck language uses a simple machine model consisting of the program and instruction pointer, as well as a one-dimensional array of at least 30,000 byte cells initialized to zero; a movable data pointer (initialized to point to the leftmost byte of the array); and two streams of bytes for input and output (most often connected to a keyboard and a monitor respectively, and using the ASCII character encoding).

The eight language commands each consist of a single character:
|character|meaning|
:--------:|-------
|`>`      | Increment the data pointer by one (to point to the next cell to the right).
|`<`      | Decrement the data pointer by one (to point to the next cell to the left).
|`+`      | Increment the byte at the data pointer by one.
|`-`      | Decrement the byte at the data pointer by one.
|`,`      | Accept one byte of input, storing its value in the byte at the data pointer.
|`.`      | Output the byte at the data pointer.
|`[`      | If the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
|`]`      | If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.

