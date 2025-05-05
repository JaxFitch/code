/*
 * KeyedItem.java
 * Jackson Fitch
 * 4/28/2025
 */

package assg9_fitchj23;

public abstract class KeyedItem<KT extends Comparable<? super KT>> {

	private KT searchKey;

	public KeyedItem(KT key) {
		searchKey = key;
	}

	public KT getKey() {
		return searchKey;
	}
}