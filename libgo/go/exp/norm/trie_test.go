package norm

import (
	"testing"
	"unicode/utf8"
)

// Test data is located in triedata_test.go; generated by maketesttables.
var testdata = testdataTrie

type rangeTest struct {
	block   uint8
	lookup  byte
	result  uint16
	table   []valueRange
	offsets []uint16
}

var range1Off = []uint16{0, 2}
var range1 = []valueRange{
	{0, 1, 0},
	{1, 0x80, 0x80},
	{0, 2, 0},
	{1, 0x80, 0x80},
	{9, 0xff, 0xff},
}

var rangeTests = []rangeTest{
	{10, 0x80, 1, range1, range1Off},
	{10, 0x00, 0, range1, range1Off},
	{11, 0x80, 1, range1, range1Off},
	{11, 0xff, 9, range1, range1Off},
	{11, 0x00, 0, range1, range1Off},
}

func TestLookupSparse(t *testing.T) {
	for i, test := range rangeTests {
		n := trie{sparse: test.table, sparseOffset: test.offsets, cutoff: 10}
		v := n.lookupValue(test.block, test.lookup)
		if v != test.result {
			t.Errorf("LookupSparse:%d: found %X; want %X", i, v, test.result)
		}
	}
}

// Test cases for illegal runes.
type trietest struct {
	size  int
	bytes []byte
}

var tests = []trietest{
	// illegal runes
	{1, []byte{0x80}},
	{1, []byte{0xFF}},
	{1, []byte{t2, tx - 1}},
	{1, []byte{t2, t2}},
	{2, []byte{t3, tx, tx - 1}},
	{2, []byte{t3, tx, t2}},
	{1, []byte{t3, tx - 1, tx}},
	{3, []byte{t4, tx, tx, tx - 1}},
	{3, []byte{t4, tx, tx, t2}},
	{1, []byte{t4, t2, tx, tx - 1}},
	{2, []byte{t4, tx, t2, tx - 1}},

	// short runes
	{0, []byte{t2}},
	{0, []byte{t3, tx}},
	{0, []byte{t4, tx, tx}},

	// we only support UTF-8 up to utf8.UTFMax bytes (4 bytes)
	{1, []byte{t5, tx, tx, tx, tx}},
	{1, []byte{t6, tx, tx, tx, tx, tx}},
}

func mkUTF8(r rune) ([]byte, int) {
	var b [utf8.UTFMax]byte
	sz := utf8.EncodeRune(b[:], r)
	return b[:sz], sz
}

func TestLookup(t *testing.T) {
	for i, tt := range testRunes {
		b, szg := mkUTF8(tt)
		v, szt := testdata.lookup(b)
		if int(v) != i {
			t.Errorf("lookup(%U): found value %#x, expected %#x", tt, v, i)
		}
		if szt != szg {
			t.Errorf("lookup(%U): found size %d, expected %d", tt, szt, szg)
		}
	}
	for i, tt := range tests {
		v, sz := testdata.lookup(tt.bytes)
		if int(v) != 0 {
			t.Errorf("lookup of illegal rune, case %d: found value %#x, expected 0", i, v)
		}
		if sz != tt.size {
			t.Errorf("lookup of illegal rune, case %d: found size %d, expected %d", i, sz, tt.size)
		}
	}
}

func TestLookupUnsafe(t *testing.T) {
	for i, tt := range testRunes {
		b, _ := mkUTF8(tt)
		v := testdata.lookupUnsafe(b)
		if int(v) != i {
			t.Errorf("lookupUnsafe(%U): found value %#x, expected %#x", i, v, i)
		}
	}
}

func TestLookupString(t *testing.T) {
	for i, tt := range testRunes {
		b, szg := mkUTF8(tt)
		v, szt := testdata.lookupString(string(b))
		if int(v) != i {
			t.Errorf("lookup(%U): found value %#x, expected %#x", i, v, i)
		}
		if szt != szg {
			t.Errorf("lookup(%U): found size %d, expected %d", i, szt, szg)
		}
	}
	for i, tt := range tests {
		v, sz := testdata.lookupString(string(tt.bytes))
		if int(v) != 0 {
			t.Errorf("lookup of illegal rune, case %d: found value %#x, expected 0", i, v)
		}
		if sz != tt.size {
			t.Errorf("lookup of illegal rune, case %d: found size %d, expected %d", i, sz, tt.size)
		}
	}
}

func TestLookupStringUnsafe(t *testing.T) {
	for i, tt := range testRunes {
		b, _ := mkUTF8(tt)
		v := testdata.lookupStringUnsafe(string(b))
		if int(v) != i {
			t.Errorf("lookupUnsafe(%U): found value %#x, expected %#x", i, v, i)
		}
	}
}
