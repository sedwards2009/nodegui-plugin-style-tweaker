# nodegui-plugin-style-tweaker

A `QStyle` which acts as a proxy on top of another style and makes it possible to tweak pixel metrics returned by the base style.


[NodeGui](https://github.com/nodegui/nodegui).

TypeScript example:

```typescript
//...
import {  } from 'nodegui-plugin-style-tweaker';
//...

```


Install via NPM:

```
npm install nodegui-plugin-style-tweaker
```

For the API see [src/index.ts](src/index.ts)

For a complete demo see [src/demo.ts](src/demo.ts)

# Maintainer

Simon Edwards <simon@simonzone.com>

# License

MIT

# Release Process (for maintainers)

* Make sure the version in `package.json` is correct.
* Tag the version with git (format: v1.2.3).
* Push the tag to origin.
* Wait for GitHub Action to build and release to NPM.
