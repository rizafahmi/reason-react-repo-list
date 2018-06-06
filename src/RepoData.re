type repo = {
  full_name: string,
  stargazers_count: int,
  html_url: string,
};

let parseRepoJson = (json: Js.Json.t) : repo =>
  Json.Decode.{
    full_name: field("full_name", string, json),
    stargazers_count: field("stargazers_count", int, json),
    html_url: field("html_url", string, json),
  };
