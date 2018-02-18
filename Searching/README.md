<h2>Searching</h2>
<p>
	<h4>Problem: Suppose we have array or list of having 'n' element and we want to find given element from it.</h4>
</p>
<h4>Solution:</h4>
<p>
	<strong>Linear Searching:</strong> Linear search or sequential search is a method for finding a target value within a list. Means we check one-by-one each element from list or array. It takes <i>O(n)</i> time in worst case to find the element. <i><a href="https://github.com/milansonagra/My-Data-Stuctures-and-Algorithm/blob/master/Searching/Linear%20Searching.c">click for code</a></i>
</p>
<p>
	<strong>Jump Searching:</strong>  jump search or block search refers to a search algorithm for ordered lists.
	Here are the steps for Jump Search:
	<ol type="1">
		<li>Sort the array or list</li>
		<li>compare the element with first element of array or list if both are same, you find the element.</li>
		<li>if it is not same skip &#x221A;n element (jump of &#x221A;n) and compare until the element is less then the element from array or list</li>
		<li>if the element is grater then the element we finding, jump back and perform linear search up-to &#x221A;n if the element is not found up-to next &#x221A;n element, it is not in array or list.</li>
	</ol>
	It takes <i>O(&#x221A;n)</i> time in worst case to find the element from sorted list or array. <i><a href="https://github.com/milansonagra/My-Data-Stuctures-and-Algorithm/blob/master/Searching/Jump%20Search.c">click for code</a></i>
</p>
<p>
	<strong>Binary Search:</strong> In computer science, binary search, also known as half-interval search, logarithmic search, or binary chop, is a search algorithm that finds the position of a target value within a sorted array.It takes <i>O(log<sub>2</sub> n)</i> time in worst case to find the element from sorted list or array. <i><a href="https://github.com/milansonagra/My-Data-Stuctures-and-Algorithm/blob/master/Searching/Binary%20Search.c">click for code</a></i>
</p>
