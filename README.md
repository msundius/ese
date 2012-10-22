I've worked as and embedded engineer and consultant for over 20 years and in that Time I've seen
lots of embedded systems applications that were wrongly designed from a system standpoint. The effects of this
are that the software becomes complicated and cumbersome to work with. While its easy to
develop a simple embedded system, things get complicated very quickly if you start out with a
simplistic sense of programming. The biggest problem is that most embedded applications prototypes
are created with a simple 'for loop' and almost no application infrastructure or fore-
thought. Once the develpers get a bit down the road with this they quickly find that there
are limits to the original concept. the crux comes now: if managers don't allow you to re-write
the basic framework and infrastructure in a more elegant way, then the project is doomed to be forever
a mess of jumbled code and developers be consumed with complexities that cannot be overcome. Since each project
I work on I end up rewriting the same code each and every time, I have decided to provide 
a set of embedded systems environment structures and frameworks that are almost always required and allow for
a more elegant organization. I'll also note that since many of the concepts applied in this library are
taking from my experience as an OS kernel developer, I find that they are almost never considered by
application programmers who have worked in higher level middleware and application development. I'm
not saying that they can or do not understand it, rather they simply rarely (in my experience) ever
consider using them. 

My goal is to develop framework and environment software which supports embedded systems software programming.
By this, I mean software which is deisgned to run embedded systems applications which are efficient
modular and flexible; They should be easy to maintain and extensible without becoming bogged down
with speghetti like topologies. To this end this software tries to push the following priciples:

1) good coding style. close to the linux kernel coding standard. use of dyoxygyn, and < 100 chars
per line, and consistent use of indentation etc. see ./docs/codingstandars

2) use of state machines. to Avoid complicated for/while loops the use of FSm structures should
be used whenever a thread's program loop becomes too complicated

3) use of non-blocking driver interfaces should be used whenever possible. blocking calls and 
sleep should just about never be used. Callbacks should be the preferred way of signaling 
completion of a task is almost all circumstances

4) deferred procedure calls and DPC scheduling should be the basis of all asynchronous activity.
this removes the responsibility of higher level code calling blocking functions which wait for 
this activity

5) good debug facilities including premodule debugging statements,runtime tyep checking and 
pervasive assertions should be used fanatically

6) thought to scalability should always be kept in mind. with respect to resources like 
memory, buffers, locking, threads etc.

7) use of standard interfaces such as posix primatives and libc 

8) Never call sleep()
