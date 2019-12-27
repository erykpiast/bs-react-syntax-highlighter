[@bs.config {jsx: 2}];

open Jest;
open ExpectJs;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let renderReason = () => (
  <div>
    <ReactSyntaxHighlighter.Jsx2>
    ...{""}
    </ReactSyntaxHighlighter.Jsx2>
  </div>
) |> Enzyme.shallow |> Enzyme.Shallow.childAt(0);

let renderJs = [%bs.raw "() => React.createElement(require('react-syntax-highlighter').default, {}, '')"];

describe("jsx2", () => {
  test("output equal to direct JS rendering", () => {
    let reasonComponent = renderReason();
    let jsComponent = [%bs.raw "renderJs()"];

    expect(Enzyme.Shallow.equals(jsComponent, reasonComponent)) |> toBe(true)
  });
});