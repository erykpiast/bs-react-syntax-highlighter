# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.

## [0.2.0](https://github.com/erykpiast/bs-react-syntax-highlighter/compare/v0.1.1...v0.2.0) (2020-01-04)


### ⚠ BREAKING CHANGES

* **api:** `lineProps` accepts polymorphic variant instead of `ReactDOMRe.props` type

Change the existing code as follows:

```diff
-let props = ReactDOMRe.props(~className="foobar", ());
+let props = `Plain( ReactDOMRe.props(~className="foobar", ()) );

<ReactSyntaxHighlighter.Prism lineProps={props}>
  {"foobar"}
</ReactSyntaxHighlighter.Prism>
```

### Features

* **api:** add support for defining `lineProps` as a function ([6b38614](https://github.com/erykpiast/bs-react-syntax-highlighter/commit/6b3861467fe2e14dc910220a142b57135c5a522c))

### [0.1.1](https://github.com/erykpiast/bs-react-syntax-highlighter/compare/v0.1.0...v0.1.1) (2020-01-01)


### Bug Fixes

* **lint:** change letter case for excluded word ([b5f6695](https://github.com/erykpiast/bs-react-syntax-highlighter/commit/b5f6695b2a4bc347d2711dcab2a77e52ce4d9c60))

## 0.1.0 (2020-01-01)

Initial release.

# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.
