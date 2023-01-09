# 1337-FT_CONTAINERS

<details>
    <summary>Table of Contents</summary>
    <ol>
        <li>
        <a href="#about-the-project">About The Project</a>
        </li>
        <li>
        <a href="#roadmap">Roadmap</a>
        </li>
        <li><a href="#resources">Resources</a>
        </li>
    </ol>
</details>

<br></br>
# About The Project

<!-- Screenshot -->

**FT_CONTAINERS is a project i've worked on during my studies at 1337 the purpose of the project is to reimplement three of the most used CPlusPlus STL containers (or four if you want to do the bonus part).**

<ins>*the three containers are*</ins>
* one sequence container **vector**
* one sequence container adapter **stack**
* one associative container **map**
* another associative container **set** (in bonus part)


### - **UTILITIES FOR THE VECTOR**
* *Random access iterator* to traverse the container
* *enable_if* and *is_integral* used in some methods that requires dealing with input iterators and integers

### - **UTILITIES FOR THE MAP**
* a *redBlackTree* class which implements most of the methods in the map container
* *bidirectional_iterator* to traverse the map
* a *pair* class to hold the value of the node in tree

### - **COMMON UTILITIES**
* *lexicographical_compare* and *equal* template functions are used in relational operators of the containers
* *reverse_iterator* template class to reverse an given iterator passed to it

<br></br>

# Roadmap

**if I had to retry the project i would've avoided lots of mistakes i did during my implementation of the containers these are my tips for each container.**

## Vector
* if you implemented a well-tested method of the vector try to use it in the other methods
* write a method for managing the capacity of the vector that treats all the cases
* focus on writing fast code and keep your file organized 
* if a some point you need an temporary array use your vector instead

## Map

* write a battle-tested tree class that uses the allocator properly and implements all the methods of the map
* once your done with the tree start implementing the tree iterator which is gonna be bidirectional if your iterator, const_iterator, reverse_iterator and const_reverse_iterator are functioning you can pass to the map 

* at this point the map is easy you just create the constructors and keep calling the _tree corresponding method whenever you needed

## COMMON TIPS
* most of the testers tests the time-complexity of your container so try to optimize your code as much as you can
* devide your code just like if norminette exists
* don't try to create your tree algorithms the insert, delete and search methods exists understand how they work and use them don't get overwhelmed


# Resources
* <a href="https://www.drdobbs.com/stl-generic-programming-writing-your-ow/184401417">Understand Generic Programming with templates</a>
* <a href="https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp">Writing a costume Iterator</a>

* <a href="https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf">header files of the container</a>

* <a href="https://containersfordummies.notion.site/THE-ULTIMATE-GUIDE-e7f20768377544409ca8d036b1ab9b7f">FT_CONTAINERS guide</a>

* <a href="https://www.codeproject.com/Articles/4795/C-Standard-Allocator-An-Introduction-and-Implement"> Understanding allocators </a>

* <a href="https://earthy-mandarin-bcd.notion.site/Containers-81cacfaf4f0543bcb76ad44b0127cdb7">a guide written by zqadiri the goat</a>
