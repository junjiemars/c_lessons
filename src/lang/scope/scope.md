# Scope & Storage

## Declarations and Definitions
* All declarations with no [linkage](#linkage) are also definitions. Other 
declarations are definitions if they have an initializer.
* A [file scope](#file-scope) variable declaration without the 
[extern](#extern) storage class specifier or initializer is a tentative definition.
* All definitions are declarations but not vice-versa.
* A definition of an identifier is a declaration for that identifier that:
for an object, causes storage to be reserved for that object.
 
## Scope
The scope of a [declaration](#declaration-and-definition) is the part of the code 
where the declaration is seen and can be used. Note that this says nothing about 
whether the object associated to the declaration can be accessed from some other part of the code via another declaration. We uniquely identify an object by its memory: 
the storage for a variable or the function code.

Finally, note that a [declaration](#declaration-and-definition) in a nested scope can hide a declaration in an outer scope; but only if one of two has no 
[linkage](#linkage).


### Duration
Indicates whether the object associated to the 
[declaration](#declaration-and-definition) persists throughout the program's 
execution or whether it is allocated dynamically when the declaration's scope 
is entered.

### Linkage
**Linkage** is what determines if multiple declarations of the same object refer to
the same object, or to separate ones. Each declaration can only have one of five 
[storage](#storage) class specifier: 
**static**, **extern**, **auto**, **register** and **typedef**.

**No Linkage**: A declaration with no linkage is associated to an object that
is not shared with any other declaration. All declarations with no linkage
happen at block scope: all block scope declarations without the extern storage
class specifier have no linkage.

**Internal Linkage**: within the compilation unit, all declarations with internal 
linkage for the same identifier refer to the same object.

**External Linkage**: within the whole program, all declarations with external
linkage for the same identifier refer to the same object.


### Block Scope 
Every variable or function declaration that appears inside a block
(including a function body) has block scope. The scope goes from the declaration to
the end of the innermost block in which the declaration appears. Function parameter
declarations in function definitions (but not in prototypes) also have block scope.
The scope of a parameter declaration therefore includes the parameter declarations
that appears after it.

### Function Scope
**goto** label is a bit special, which are implicitly declared at the place where 
they appears, but they are visible throughout the function, even if they appear 
inside a block.

**function prototype scope** is the scope for function parameters that appears
inside a function prototype. It extends until the end of the prototype. This
scope exists to ensure that function parameters have distinct names.

### File Scope
All vairables and functions defined ouside functions have [file scope](#file-scope).
They are visible from their [declaration](#declaration-and-definition) until the 
end of the file. Here, the term **file** should be understood as the source file 
being compiled, after all includes have been resolved.


## Storage

### auto 
This storage class denotes that an identifier has automatic storage duration. This
means once the scope in which the identifier was defined ends, the object denoted
by the identifier is no longer valid.

Since all objects, not living in **global** scope or being declared **static**, have
automatic storage duration by default when defined, this keyword is mostly of 
historical interest and should not be used.

* **auto** can't apply to parameter declarations. It is the default for variable
declared inside a function body, and is in fact a historic leftover 
from C predecessor's B.
* automatic variables includes global_auto_i0/i1, i0/i1;
* uninitialized variables will be set to 0;


### register 
Hints to the compiler that access to an object should as fast as possible. 
Whether the compiler actually uses the hint is implementation-defined; it may simply
treat it as equivalent to **auto**.

The compiler does make sure that you do not take the address of a vairable with
the register storage class.

The only property that is definitively different for all objects that are declared 
with **register** is that they cannot have their address computed. 
Thereby **register** can be a good tool to ensure centain optimizations:


```c
/* error: address of register variable requested */
register int i4 = 0x10;
int* p = &i4;
sqr(*(&i4));
```

```i4``` that can never alias because no code can pass its address to another 
function where it might be changed unexpectedly.

This property also implies that an array
```c
register int a[5];
```
cannot decay into a pointer to its first element (i.e. turning into ```&a[0]```).
This means that the elements of such an array cannot be accessed and the array itself
cannot be passed to a function.

In fact, the only legal usage of an array declared with a ```register``` storage class
is the ```sizeof``` operator; Any other operator would require the address of the
first element of the array. For that reason, arrays generally should not be declared
with the ```register``` keyword since it makes them useless for anything other than
size computation of the entire array, which can be done just as easily without 
```register``` keyword.

The ```register``` storage class is more appropriate for variables that are defined 
inside a block and are accessed with high frequency.


### static 
The **static** storge class serves different purposes, depending on the location
of the declaration in the file:
* Confine the identifier to that **translation unit** only (scope=file);
* Save data for use with the next call of a function (scope=block); 
* >=C99, used in function parameters to denote an array is expected to have a 
constant minimum number of elements and a non-null parameter.

### extern 
**extern** keyword used to declare an object or function that is defined 
elsewhere (and that has **external linkage**). In general, it is used to declare an object or function to be used in a module that is not the one in which the corresponding
object or function is defined. 


## References
* [C: Scope, Duration & Linkage](http://norswap.com/c_scope_duration_linkage/)
* [C Language: Storage Classes](http://stackoverflow.com/documentation/c/3597/storage-classes#t=201702091201208256422) 