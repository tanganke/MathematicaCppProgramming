Working in progress.

### data type correspondence

| Wolfram Language Specification    | C Specification | Description                             |
| :-------------------------------- | --------------- | --------------------------------------- |
| "Boolean"                         | mbool           | Boolean                                 |
| Integer                           | mint            | machine integer                         |
| Real                              | double          | machine double                          |
| Complex                           | mcomplex        | machine complex double                  |
| {base,rank}                       | MTensor         | tensor of specified base type and rank  |
| {base,rank,memory}                | MTensor         | tensor with specified memory management |
| LibraryDataType[SparseArray,...]  | MSparseArray    | sparse array                            |
| LibraryDataType[NumericArray,...] | MNumericArray   | numeric array                           |
| LibraryDataType[ByteArray]        | MNumericArray   | byte array                              |
| LibraryDataType[Image,...]        | MImage          | 2D image                                |
| LibraryDataType[Image3D,...]      | MImage          | 3D image                                |
| "UTF8String"                      | char *          | UTF8 string                             |
| LinkObject                        | WSLINK          | arguments and result written to WSTP    |
| "Void"                            |                 | no result (return only)                 |

