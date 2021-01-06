# TimerCpp

A more reliable implementation of [99x's timercpp](https://github.com/99x/timercpp).

## Usage

Add `timercpp.h` and `timercpp.cpp` to your project.

```cpp
	Timer timer;   

	timer.setInterval([=]()
	{
		static int cnt = 0;
		++cnt;
		std::cout << "- Count " << cnt << std::endl;
	}, 1000);

	//Note that new task will kill previous task if it exists.
	timer.setTimeout([=]()
	{
		std::cout << "- Timeout" << std::endl;
	}, 1000);

	//Kill background task, it will be automatically killed when leaving a scope.
	timer.stop();
```

> Automatically stop when leaving scope.
>
> ```cpp
> void scope()
> {
> 	Timer timer;
> 	timer.setTimeout([=]()
> 	{
> 		std::cout << "- Timeout" << std::endl;
> 	}, 1000);
>     
>     //Stops when leaving
> }
> 
> int main()
> {
> 	scope();
> 	//Will print nothing.
>     ...
> }
> ```

## Dependencies

Unlike [99x's timercpp](https://github.com/99x/timercpp), this project uses `boost.thread` for interrupt feature.

> You can use `vcpkg` to install `boost`
>
> ```
> ./vcpkg install boost
> ```

## Limits

Only **one** task per Timer object.

