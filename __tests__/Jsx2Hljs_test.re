[@bs.config {jsx: 2}];

open Jest;
open ExpectJs;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("jsx2", () => {
  test("empty", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs.Jsx2>
      ...{""}
      </ReactSyntaxHighlighter.Hljs.Jsx2>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { },
        '')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("language", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs.Jsx2 language={`JavaScript}>
      ...{"const foo = () => {};"}
      </ReactSyntaxHighlighter.Hljs.Jsx2>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { language: 'javascript' },
        'const foo = () => {};')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("style", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs.Jsx2 style={ReactSyntaxHighlighter.Hljs.Style.dracula}>
      ...{"foobar"}
      </ReactSyntaxHighlighter.Hljs.Jsx2>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { style: require('react-syntax-highlighter/dist/esm/styles/hljs').dracula },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("renderer", () => {
    let renderer: ReactSyntaxHighlighter.Hljs.Renderer.t = (input) => {
      let theFirstRow = List.nth(input##rows, 0);
      let theFirstElement = List.nth(theFirstRow##children, 0);
      let textNode = List.nth(theFirstElement##children, 0);
      let text = textNode##value;

      text |> React.string;
    };
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs.Jsx2 renderer>
      ...{"foobar"}
      </ReactSyntaxHighlighter.Hljs.Jsx2>
    ) |> Enzyme.shallow;
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { renderer: (props) => props.rows[0].children[0].children[0].value },
        'foobar')
    "] |> Enzyme.shallow;

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("pre tag", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs.Jsx2 _PreTag={<span />}>
      ...{"foobar"}
      </ReactSyntaxHighlighter.Hljs.Jsx2>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { PreTag: require('react').createElement('span') },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });
});