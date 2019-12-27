open Jest;
open ExpectJs;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let renderReason = () => (
  <div>
    <ReactSyntaxHighlighter>
    {""}
    </ReactSyntaxHighlighter>
  </div>
) |> Enzyme.shallow |> Enzyme.Shallow.childAt(0);

let renderJs = [%bs.raw "() => React.createElement(require('react-syntax-highlighter').default, {}, '')"];

describe("jsx3", () => {
  test("output equal to direct JS rendering", () => {
    let reasonComponent = renderReason();
    let jsComponent = [%bs.raw "renderJs()"];

    expect(Enzyme.Shallow.equals(jsComponent, reasonComponent)) |> toBe(true)
  });
});
