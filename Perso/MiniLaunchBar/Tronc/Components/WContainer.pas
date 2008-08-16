unit WContainer;

interface

uses
  SysUtils, Classes, Controls, ExtCtrls, PNGImage, Imaging, Graphics, StdCtrls, Types,
  WComponent, Windows, Forms, Messages;
  
type
  TWContainer = class(TWComponent)
  private
    { Private declarations }
    children: Array of TWComponent;

    procedure UpdateChildrenLocation();

  protected
    { Protected declarations }
    procedure Paint; override;

  public
    { Public declarations }
    constructor Create(AOwner: TComponent); override;
  published
    { Published declarations }
    procedure AddChild(const child: TWComponent);
  end;

procedure Register;

implementation


procedure Register;
begin
  RegisterComponents('Samples', [TWContainer]);
end;


constructor TWContainer.Create(AOwner: TComponent);
begin
  {Calls ancestor}
  inherited Create(AOwner);
end;


procedure TWContainer.Paint;
begin
	inherited;
  UpdateChildrenLocation();
end;


procedure TWContainer.AddChild(const child: TWComponent);
begin
  child.ParentContainer := self;
  SetLength(children, Length(children) + 1);
  children[Length(children) - 1] := child;
  Invalidate();
end;


procedure TWContainer.UpdateChildrenLocation();
var i: Integer;
begin
	if Length(children) = 0 then Exit;

  for i := 0 to Length(children) - 1 do begin
  	children[i].UpdateLocation();	  	
  end;
end;


end.


