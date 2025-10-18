class BinaryTree
{
    constructor( data, leftTree = null, rightTree = null )
    {
        this.data = data;
        this.leftSubTree = leftTree;
        this.rightSubTree = rightTree;
    } // constructor

    getData()
    {
        return this.data;
    } // getData()
    setData( data )
    {
        this.data = data;
    } // setData()

    getLeftSubTree()
    {
        return this.leftSubTree;
    } // getLeftSubTree()
    setLeftSubTree( leftTree )
    {
        this.leftSubTree = leftTree;
    } // setLeftSubTree()
    
    getRightSubTree()
    {
        return this.rightSubTree;
    } // getRightSubTree()
    setRightSubTree( rightTree )
    {
        this.rightSubTree = rightTree;
    } // setRightSubTree()

    preOrderTraversal( LootTree )     // 루트 > 왼쪽 > 오른쪽
    {
        if( LootTree == null ) return;
        console.log( LootTree.getData() );
        this.preOrderTraversal( LootTree.getLeftSubTree() );
        this.preOrderTraversal( LootTree.getRightSubTree() );
    } // preOrderTraversal()

    inOrderTraversal( LootTree )     // 왼쪽 > 루트 > 오른쪽
    {
        if( LootTree == null ) return;
        this.inOrderTraversal( LootTree.getLeftSubTree() );
        console.log( LootTree.getData() );
        this.inOrderTraversal( LootTree.getRightSubTree() );
    } // inOrderTraversal()
    
    postOrderTraversal( LootTree )     // 왼쪽 > 오른쪽 > 루트
    {
        if( LootTree == null ) return;
        this.postOrderTraversal( LootTree.getLeftSubTree() );
        this.postOrderTraversal( LootTree.getRightSubTree() );
        console.log( LootTree.getData() );
    } // postOrderTraversal()

    removeLeftSubTree()
    {
        let deleteNode = this.getLeftSubTree();
        this.setLeftSubTree( null );
        return deleteNode;
    } // removeLeftSubTree()
    removeRightSubTree()
    {
        let deleteNode = this.getRightSubTree();
        this.setRightSubTree( null );
        return deleteNode;
    } // removeRightSubTree()

} // BinaryTree

export { BinaryTree };