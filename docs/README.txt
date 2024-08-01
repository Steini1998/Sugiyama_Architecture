- Sugiyama-Class will be initialized with all required steps
	and holds a reference to the original graph and positions.

- Each step will only work on the original graph and positions, and will
	save an independent snapshot of the graph and positions with itself.
	
- After all steps are executed and the original graph and positions are updated 
	sequentially, we can step over the snapshots in each direction.
